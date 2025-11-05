
#ifndef GAMEEXCEPTION_H
#define GAMEEXCEPTION_H

#include <exception>

class GameException : public std::exception {
    public:
    virtual const char* what() const noexcept = 0;
    virtual ~GameException(){}
};

class MemoryException : public GameException {
    public:
    const char* what() const noexcept { return "Memory Problem"; }
};

class RoomException : public GameException {
    public:
    const char* what() const noexcept { return "Invalid Room"; }
};

class ValueException : public GameException {
    public:
    const char* what() const noexcept { return "Invalid Value"; }
};
#endif //GAMEEXCEPTION_H
