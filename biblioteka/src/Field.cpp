#include "../includes/Field.hpp"

using namespace Lukasz;

Field::Field(position myPos, position parentPos){
    m_myPos = myPos;
    m_parentPos = parentPos;
}

position Field::getParent(){
    return m_parentPos;
}

