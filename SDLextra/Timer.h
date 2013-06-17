/*
 * Timer.h
 *
 *  Created on: Sep 10, 2011
 *      Author: felix
 */

#ifndef TIMER_H_
#define TIMER_H_

class Timer {
private:
    //The clock time when the timer started
    int 	startTicks_;

    //The ticks stored when the timer was paused
    int 	pausedTicks_;

    //The timer status
    bool 	isPaused_, isStarted_;

public:
    //Initializes variables
	Timer();

	//The various clock actions
	void start();
    void stop();
    void pause();
    void unpause();

    //Gets the timer's time
    int getTicks();

    //Checks the status of the timer
    bool isStarted();
    bool isPaused();
};

#endif /* TIMER_H_ */
