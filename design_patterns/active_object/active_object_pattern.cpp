#include <iostream>
#include <thread>
#include <queue>
#include <functional>
#include <mutex>
#include <condition_variable>

/*
Imagine you have a friend who's really good at doing tasks for you, but you don't want to
disturb them while they're busy. So, you write down the tasks you want them to do on a piece
of paper and put it in a special box. Your friend knows to check the box from time to time
and does the tasks you've written down without you having to wait for them to finish.

In this scenario:

You are the "client" who wants things done.
Your friend is the "active object" that can do tasks for you.
The box is like a queue where you put tasks you want your friend to do.
Checking the box represents the active object periodically checking for tasks and doing them.
Now, let's relate this to the Active Object Design Pattern:

Active Object: It's a special object that can do things for you asynchronously. Just like your friend who checks
the box and performs tasks without you waiting.

Method Request: This is like the task you write down on a piece of paper and put in the box.
It's a way of asking the active object to do something specific.

Scheduler: Think of this as the box-checking process. The active object periodically
looks at the tasks in the queue and performs them one by one.

Client: That's you, the one who wants things done. You send your tasks (method requests) to
the active object and continue with your own work without waiting for the tasks to finish.

The main idea of the Active Object Design Pattern is to let you use some special objects to
handle tasks asynchronously. These objects manage their own time and make sure your tasks get
done without blocking your work. It's like having a helper who takes care of things for you in the background.

In the programming world, this pattern is used to make sure that different parts of 
a program can work at the same time without waiting for each other. It's especially
useful when dealing with things that might take some time, like talking to other computers over the internet.

By using the Active Object Design Pattern, you can make your programs more efficient
and responsive, just like how you're able to get things done while your friend is busy helping you with tasks.

*/
class ActiveObject {
private:
    std::queue<std::function<void()>> methodQueue;
    std::mutex mtx;
    std::condition_variable cv;
    std::thread workerThread;
    bool stopRequested = false;

public:
    ActiveObject() {
        workerThread = std::thread(&ActiveObject::run, this);
    }

    ~ActiveObject() {
        {
            std::unique_lock<std::mutex> lock(mtx);
            stopRequested = true;
            cv.notify_all();
        }
        workerThread.join();
    }

    void run() {
        while (true) {
            std::function<void()> method;
            {
                std::unique_lock<std::mutex> lock(mtx);
                cv.wait(lock, [&] { return !methodQueue.empty() || stopRequested; });
                if (stopRequested) {
                    break;
                }
                method = std::move(methodQueue.front());
                methodQueue.pop();
            }
            method();
        }
    }

    void enqueueMethod(std::function<void()> method) {
        {
            std::lock_guard<std::mutex> lock(mtx);
            methodQueue.push(method);
        }
        cv.notify_all();
    }
};

class SomeService {
public:
    void doSomething() {
        std::cout << "SomeService is doing something" << std::endl;
    }
};

int main() {
    ActiveObject activeObject;
    SomeService service;

    activeObject.enqueueMethod([&] { service.doSomething(); });
    // Other work can continue here without waiting for doSomething() to complete

    while(true);
    // ActiveObject will automatically clean up when it goes out of scope

    return 0;
}
