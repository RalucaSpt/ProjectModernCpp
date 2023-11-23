#include <crow.h>

import match;
import word;
import round;
import player;


import <iostream>;
//import <ctime>;
//import <cstdlib>;




int main() 
{
    crow::SimpleApp app;
    CROW_ROUTE(app, "/")([]() 
        {
            return "Hello Word!";
        });
    app.port(18080).multithreaded().run();
	return 0;
}

/*skribble::Words test;
   skribble::Player player1(0,0);
   test.setWords("Words.txt");
   //std::cout<<test.getWord();
   //skribble::Round test2(test);
   //test2.guessWord(test.getWord());
   skribble::Round round1;
   round1.setPlayer(player1);
   round1.setWord(test.getWord());
   round1.guessWord();*/
   /// Match matchTest;
    //std::vector<Player> playersTest;

/*#include <chrono>
#include <thread>
*/
/*class Timer {
public:
    Timer() : start_time(std::chrono::high_resolution_clock::now()) {}

    void reset() {
        start_time = std::chrono::high_resolution_clock::now();
    }

    double getElapsedSeconds() {
        auto end_time = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_time = end_time - start_time;
        return elapsed_time.count();
    }

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start_time;
};
//#include <thread>

// This function will be executed by the first thread
void threadFunction1() {
    for (int i = 0; i < 5; i++) {
        std::cout << "Thread 1: " << i << std::endl;
    }
}

// This function will be executed by the second thread
void threadFunction2() {
    for (int i = 0; i < 5; i++) {
        std::cout << "Thread 2: " << i << std::endl;
    }
}*/






    /*std::thread t1(threadFunction1);
    std::thread t2(threadFunction2);
    Timer timer;
    int x;
    bool running = true;
    // Simulate game loop
    while (running)
    {
        // Perform game logic here



        // Join the threads to the main thread
        t1.join();
        t2.join();

        int elapsed_seconds = timer.getElapsedSeconds();
        std::cout << "Elapsed time: " << elapsed_seconds << " seconds" << std::endl;

        // Optionally reset the timer for the next frame
        //timer.reset();
        if (elapsed_seconds > 10)
        {
            running = false;
            std::cout << "Game over";
        }
    }
    std::cout << "Both threads have finished." << std::endl;*/
