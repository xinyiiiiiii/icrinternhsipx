#include "stepping.hh"

MySteppingAction::MySteppingAction(MyEventAction *eventAction)
{
    fEventAction = eventAction;
}

MySteppingAction::~MySteppingAction()
{}

void MySteppingAction::UserSteppingAction(const G4Step *step)
{   

    G4StepPoint* prePoint = step->GetPreStepPoint();
    G4StepPoint* postPoint = step->GetPostStepPoint();

    G4ThreeVector preDir = prePoint->GetMomentumDirection();
    G4ThreeVector postDir = postPoint->GetMomentumDirection();

    // Calculate the angle between the two directions
    G4double angleRad = preDir.angle(postDir);
    G4double angleDeg = angleRad * (180.0 / CLHEP::pi);

    G4cout << "Scattering angle (deg): " << angleDeg << G4endl;

    /*G4LogicalVolume *volume = step->GetPreStepPoint()->GetTouchableHandle()->GetVolume()->GetLogicalVolume();
    
    const MyDetectorConstruction *detectorConstruction = static_cast<const MyDetectorConstruction*> (G4RunManager::GetRunManager()->GetUserDetectorConstruction());
    
    G4LogicalVolume *fScoringVolume = detectorConstruction->GetScoringVolume();
    
    if(volume != fScoringVolume)
        return;
    
    G4double edep = step->GetTotalEnergyDeposit();
    fEventAction->AddEdep(edep);*/
}
