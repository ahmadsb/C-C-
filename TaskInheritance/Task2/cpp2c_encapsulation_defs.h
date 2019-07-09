#ifndef __CPP2C_ENCAPSULATION_DEFS_H__
#define __CPP2C_ENCAPSULATION_DEFS_H__

//// Box ////////////

class Box
{
public:
    Box(double dim = 1);
    Box(double l, double w, double h);
    ~Box();

    double getWidth() const;
    double getLength() const;
    double getHeight() const;

    double getVolume() const;
    
    Box& operator*=(double mult);

protected:
    void print() const;

private:    
    double width;
    double height;
    double length;
};

Box operator*(const Box& box, double mult);
Box operator*(double mult, const Box& box);
bool operator==(const Box& lhs, const Box& rhs);
bool operator!=(const Box& lhs, const Box& rhs);


//// Box Defs ////////////

inline double Box::getWidth() const
{
    return width;
}

inline double Box::getLength() const
{
    return length;
}

inline double Box::getHeight() const
{
    return height;
}

inline double Box::getVolume() const
{
    return width * length * height;
}

inline Box operator*(const Box& box, double mult)
{
    Box ret = box;
    ret *= mult;
    return ret;
}

inline Box operator*(double mult, const Box& box)
{
    return box * mult;
}

inline bool operator==(const Box& lhs, const Box& rhs)
{
    return lhs.getWidth() == rhs.getWidth() && lhs.getHeight() == rhs.getHeight() && lhs.getLength() == rhs.getLength();
}

inline bool operator!=(const Box& lhs, const Box&rhs)
{
    return !(lhs == rhs);
}


//// Shelf ////////////

class Shelf
{
public:
    void setBox(int index, const Box& dims);
    double getVolume() const;
    Box& getBox(int index);
    void print() const;
    
    static int getNumBoxes();
    static void setMessage(const char* msg);
    
private:
    static const unsigned int NUM_BOXES = 3;
    static const char* const DEF_MSG;
    static const char* message;

    Box boxes[NUM_BOXES];
};

//// Shelf Defs ////////////

inline Box& Shelf::getBox(int index)
{
    return boxes[index];
}

inline int Shelf::getNumBoxes()
{
    return NUM_BOXES;
}

inline void Shelf::setMessage(const char* msg)
{
    message = msg;
}

#endif // __CPP2C_ENCAPSULATION_DEFS_H__

