#include "stepping.hh"
#include <fstream>
#include <iomanip>

MySteppingAction::MySteppingAction(MyEventAction *eventAction)
{
    fEventAction = eventAction;
    outFile.open("scattering_angle.csv",std::ios::out);
    outFile << "ScatteringAngleDeg";
}

MySteppingAction::~MySteppingAction()
{
    if (outFile.is_open()) outFile.close();
}

void MySteppingAction::UserSteppingAction(const G4Step *step)
{   
    
    G4Track *track = step->GetTrack();

    //track->SetTrackStatus(fStopAndKill); 
if (track->GetTrackID() == 1 && track->GetTrackStatus() == fStopAndKill) {
    G4StepPoint* prePoint = step->GetPreStepPoint();
    G4StepPoint* postPoint = step->GetPostStepPoint();

    G4ThreeVector preDir = prePoint->GetMomentumDirection();
    G4ThreeVector postDir = postPoint->GetMomentumDirection();

    // Calculate the angle between 
    G4double angleRad = preDir.angle(postDir);
    G4double angleDeg = angleRad * (180.0 / CLHEP::pi);
    

    G4cout << "Scattering angle (deg): " << angleDeg << G4endl;

    outFile << std::fixed << std::setprecision(4) << angleDeg << "\n";
}

    /*G4LogicalVolume *volume = step->GetPreStepPoint()->GetTouchableHandle()->GetVolume()->GetLogicalVolume();
    
    const MyDetectorConstruction *detectorConstruction = static_cast<const MyDetectorConstruction*> (G4RunManager::GetRunManager()->GetUserDetectorConstruction());
    
    G4LogicalVolume *fScoringVolume = detectorConstruction->GetScoringVolume();
    
    if(volume != fScoringVolume)
        return;
    
    G4double edep = step->GetTotalEnergyDeposit();
    fEventAction->AddEdep(edep);*/
}
