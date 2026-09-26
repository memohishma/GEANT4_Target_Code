//the last update
#include "generator.hh"
#include "CLHEP/Random/RandGauss.h"

MyPrimaryGenerator::MyPrimaryGenerator()
{
    fParticleGun = new G4ParticleGun(1); // 
}

MyPrimaryGenerator::~MyPrimaryGenerator()
{
    delete fParticleGun; 
}

void MyPrimaryGenerator::GeneratePrimaries(G4Event *anEvent)
{
     
    G4ParticleTable *particleTable = G4ParticleTable::GetParticleTable();
    G4String particleName = "proton";
    G4ParticleDefinition *particle = particleTable->FindParticle(particleName);

    
    G4double LToTarget = 20.0 * cm; 

    
/*G4double phi =
2.0 * CLHEP::pi * CLHEP::pi *
rando*/

    G4double beamRadius = 5.0 * mm;
    G4double r = beamRadius * std::sqrt(CLHEP::HepRandom::getTheEngine()->flat()); 

    G4double phi = 2.0 * CLHEP::pi * CLHEP::HepRandom::getTheEngine()->flat();
    
    G4double posX = r * std::cos(phi);
    G4double posY = r * std::sin(phi);
    G4ThreeVector pos(posX, posY, -LToTarget); 


    
    G4double sigmaAngle = 10.0e-3; 
    G4double thetaX = G4RandGauss::shoot(0.0, sigmaAngle);
    G4double thetaY = G4RandGauss::shoot(0.0, sigmaAngle);
    
    
    G4ThreeVector mom(std::tan(thetaX), std::tan(thetaY), 1.0); 

    
    G4double meanEnergy = 2.2 * MeV;  
    G4double sigmaEnergy = 0.2 * MeV; 

    G4double energy = G4RandGauss::shoot(meanEnergy, sigmaEnergy);

    
    fParticleGun->SetParticlePosition(pos);
    fParticleGun->SetParticleMomentumDirection(mom);
    fParticleGun->SetParticleEnergy(energy);
    fParticleGun->SetParticleDefinition(particle);

    fParticleGun->GeneratePrimaryVertex(anEvent); 
}


//==============================================================================================================================//
//Pencil Beam
