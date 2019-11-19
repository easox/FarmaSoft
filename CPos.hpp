#pragma once

using namespace std;




class CPos{
  private:
    float m_f_x;
    float m_f_y;
 
  public:
    CPos();
    CPos(float m_f_x,float m_f_y);
    ~CPos();
    float get_x();
    float get_y();
};