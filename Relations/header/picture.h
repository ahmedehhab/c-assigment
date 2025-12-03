#ifndef PICTURE_H
#define PICTURE_H
class Picture
{
    private:
     void ** array;
     bool * types;
     int count;
     int capacity;
public:
    Picture(int cap);


    void  addLine(int x1,int y1,int x2,int y2);
    void addCircle(int x1,int y1,int reduis);
    void draw();
    ~Picture();
};

#endif