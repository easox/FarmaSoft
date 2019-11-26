#include "CPos.hpp"

CPos::CPos(){
  m_f_x=0;
  m_f_y=0;
};
CPos::CPos(float x,float y){
  m_f_x=x;
  m_f_y=y;
};
CPos::~CPos(){

};
float CPos::get_x(){
  return m_f_x;
};
float CPos::get_y(){
  return m_f_y;
};