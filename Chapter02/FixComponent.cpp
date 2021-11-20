#include "FixComponent.h"


FixComponent::FixComponent(Felix* owner,
    int updateOrder)
    :Component(owner, updateOrder)
{
    
}

void FixComponent::Update(float deltaTime)
{

}
     
void FixComponent::Fix(BrokenSpriteComponent* window)
{
    window->Fix();
}
