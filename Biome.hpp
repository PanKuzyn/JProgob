#pragma once

class Biome{
public:
    virtual ~Biome() = default;
    virtual char Biome_Symbol() = 0; 
    virtual std::string Biome_Color() = 0;
};

class Water : public Biome{
public:
    char Biome_Symbol() override{
        return '~';
    }
    std::string Biome_Color() override{
        return "\x1b[38;5;45m";
    }
};
class DeepWater : public Water{
public:
    std::string Biome_Color() override{
        return "\x1b[38;5;4m";
    }
};

class Plains : public Biome{
public:
    char Biome_Symbol() override{
        return '_';
    }
    std::string Biome_Color() override{
        return "\x1b[38;5;10m";
    }
};

class Forest : public Biome{
public:
    char Biome_Symbol() override{
        return 'Y';
    }
    std::string Biome_Color() override{
        return "\x1b[38;5;10m";
    }
};
class DarkForest : public Forest{
public:
    std::string Biome_Color() override{
        return "\x1b[38;5;22m";
    }
};
class Glade : public Forest{
    std::string Biome_Color() override{
        return "\x1b[38;5;155m";
    }
};

class Mountain : public Biome{
public:
    char Biome_Symbol() override{
        return '^';
    }
    std::string Biome_Color() override{
        return "\x1b[38;5;235m";
    }
};
class MountainPeaks : public Mountain{
public:
    std::string Biome_Color() override{
        return "\x1b[38;5;255m";
    }
};


class Beach : public Biome{
public:
    char Biome_Symbol() override{
        return '.';
    }
    std::string Biome_Color() override{
        return "\x1b[38;5;220m";
    }
};
