#pragma once
class Objects{
public:
    virtual ~Objects() = default;
    virtual char Object_Symbol() = 0; 
};

class Bush : public Objects{
public:
    char Object_Symbol() override{
        return '#';
    }
};

class Tree : public Objects{
public:
    char Object_Symbol() override{
        return '+';
    }
};

class TreasureChest : public Objects{
public:
    char Object_Symbol() override{
        return 'X';
    }
};


