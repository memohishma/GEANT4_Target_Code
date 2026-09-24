#include "physics.hh"

MyPhysicsList::MyPhysicsList()
{
    RegisterPhysics(new G4EmStandardPhysics()); //electromagnetic standard physics
    RegisterPhysics(new G4DecayPhysics()); //decay physics
    RegisterPhysics(new G4RadioactiveDecayPhysics()); //radioactive decay physics
    RegisterPhysics(new G4HadronPhysicsQGSP_BIC_AllHP()); //hadronic physics model

  //  RegisterPhysics(new G4HadronElasticPhysicsHP());      
  //  RegisterPhysics(new G4IonPhysicsPHP());
}

MyPhysicsList::~MyPhysicsList()
{} 
