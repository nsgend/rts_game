/*
 * Timer.cpp
 *
 *  Created on: Sep 10, 2011
 *      Author: felix
 */

#include "Timer.h"
#include <SDL/SDL.h>

Timer::Timer() {
	// TODO Auto-generated constructor stub
	//Initialize the variables
	startTicks_ = 0;
	pausedTicks_ = 0;
	isPaused_ = false;
	isStarted_ = false;

}

void Timer::start()
{
    //Start the timer
    isStarted_ = true;

    //Unpause the timer
    isPaused_ = false;

    //Get the current clock time
    startTicks_ = SDL_GetTicks();
}

void Timer::stop()
{
    //Stop the timer
    isStarted_ = false;

    //Unpause the timer
    isPaused_ = false;
}

void Timer::pause()
{
    //If the timer is running and isn't already paused
    if( ( isStarted_ == true ) && ( isPaused_ == false ) )
    {
        //Pause the timer
    	isPaused_ = true;

        //Calculate the paused ticks
        pausedTicks_ = SDL_GetTicks() - startTicks_;
    }
}

void Timer::unpause()
{
    //If the timer is paused
    if( isPaused_ == true )
    {
        //Unpause the timer
    	isPaused_ = false;

        //Reset the starting ticks
        startTicks_ = SDL_GetTicks() - pausedTicks_;

        //Reset the paused ticks
        pausedTicks_ = 0;
    }
}

int Timer::getTicks()
{
    //If the timer is running
    if( isStarted_ == true )
    {
        //If the timer is paused
        if( isPaused_ == true )
        {
            //Return the number of ticks when the timer was paused
            return pausedTicks_;
        }
        else
        {
            //Return the current time minus the start time
            return SDL_GetTicks() - startTicks_;
        }
    }

    //If the timer isn't running
    return 0;
}

bool Timer::isStarted()
{
    return isStarted_;
}

bool Timer::isPaused()
{
    return isPaused_;
}
