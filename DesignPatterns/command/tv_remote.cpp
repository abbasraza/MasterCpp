#include <iostream>
#include <vector>

/*
    In this example, we have:
    Command interface and concrete command classes (TurnOnCommand, TurnOffCommand, ChangeChannelCommand) that represent different actions.
    TV class as the receiver, which performs the actual actions when the commands are executed.
    RemoteControl class as the invoker, holding a list of commands and allowing you to press buttons to execute them.
    Running this code will simulate a TV remote control, where you can turn the TV on/off and change the channel using commands.
*/

// Receiver class
class TV {
public:
    void turnOn() {
        std::cout << "TV is now on" << std::endl;
    }

    void turnOff() {
        std::cout << "TV is now off" << std::endl;
    }

    void changeChannel(int channel) {
        std::cout << "Channel changed to " << channel << std::endl;
    }
};


// Command interface
class Command {
public:
    virtual void execute() = 0;
};

// Concrete command classes
class TurnOnCommand : public Command {
private:
    class TV *tv;

public:
    TurnOnCommand(class TV *t) : tv(t) {}

    void execute() override {
        tv->turnOn();
    }
};

class TurnOffCommand : public Command {
private:
    class TV *tv;

public:
    TurnOffCommand(class TV *t) : tv(t) {}

    void execute() override {
        tv->turnOff();
    }
};

class ChangeChannelCommand : public Command {
private:
    class TV *tv;
    int channel;

public:
    ChangeChannelCommand(class TV *t, int ch) : tv(t), channel(ch) {}

    void execute() override {
        tv->changeChannel(channel);
    }
};


// Invoker class
class RemoteControl {
private:
    std::vector<Command *> commands;

public:
    void setCommand(Command *cmd) {
        commands.push_back(cmd);
    }

    void pressButton(int index) {
        if (index >= 0 && index < commands.size()) {
            commands[index]->execute();
        } else {
            std::cout << "Invalid button pressed" << std::endl;
        }
    }
};

int main() {
    TV tv;

    TurnOnCommand turnOn(&tv);
    TurnOffCommand turnOff(&tv);
    ChangeChannelCommand changeChannel(&tv, 5);

    RemoteControl remote;
    remote.setCommand(&turnOn);
    remote.setCommand(&turnOff);
    remote.setCommand(&changeChannel);

    remote.pressButton(0); // Output: TV is now on
    remote.pressButton(2); // Output: Channel changed to 5
    remote.pressButton(1); // Output: TV is now off
    remote.pressButton(3); // Output: Invalid button pressed

    return 0;
}
