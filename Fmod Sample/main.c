//
//  main.c
//  Fmod Sample
//
//  Created by Sean DeNigris on 11/21/13.
//  Copyright (c) 2013 Sean DeNigris. All rights reserved.
//

#define SOUND_FILE_PATH "/Users/sean/Documents/Microsoft User Data/Entourage Script Menu Items/trainwhistle.mp3"

#include <stdio.h>
#include <stdlib.h>
#include "FMOD Programmers API/api/lowlevel/inc/fmod.h"

int exitOnError(int errCode)
{
    exit(errCode);
}

int main(int argc, const char * argv[])
{

    FMOD_SYSTEM* system;
    FMOD_RESULT err = FMOD_System_Create(&system);
    if (err != 0) exitOnError(err);
    
    err = FMOD_System_Init(system, 32, FMOD_INIT_NORMAL, 0);
    if (err != 0) exitOnError(err);
    
    FMOD_SOUND * sound;
    err = FMOD_System_CreateSound(system, SOUND_FILE_PATH,
                                        FMOD_HARDWARE,
                                        0,
                                        &sound);
    if (err != 0) exitOnError(err);
    
    FMOD_CHANNEL *channel;
    FMOD_System_PlaySound(
                          system,
                          sound,
                          0,
                          0,
                          &channel
                          );
    if (err != 0) exitOnError(err);
    
    FMOD_BOOL isPlaying = 1;
    while (isPlaying) {
        FMOD_Channel_IsPlaying(channel, &isPlaying);
    }

    err = FMOD_Sound_Release(sound);
    if (err != 0) exitOnError(err);
    err = FMOD_System_Close(system);
    if (err != 0) exitOnError(err);
    err = FMOD_System_Release(system);
    if (err != 0) exitOnError(err);
    
    printf("Returned %d\n", err);
    return 0;
}

