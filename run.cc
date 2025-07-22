#include "run.hh"
#include "G4SystemOfUnits.hh"
MyRunAction::MyRunAction()
{}

MyRunAction::~MyRunAction()
{}


void MyRunAction::BeginOfRunAction(const G4Run*)
{
    G4AnalysisManager *man = G4AnalysisManager::Instance();
    
    //G4String fileName = "test" + std::to_string(run->GetRunID()) + ".csv"; 
    man->OpenFile("test.csv");
    
    man->CreateNtuple("MyNtuple","MySimulationData");
    man->CreateNtupleIColumn("eventID");
    man->CreateNtupleDColumn("Edep");
    man->CreateNtupleSColumn("Pname");
    man->FinishNtuple(0);
}


void MyRunAction::EndOfRunACtion(const G4Run*)
{
    G4AnalysisManager *man = G4AnalysisManager::Instance();

    man->Write();
    man->CloseFile();
} 
