#include <Arduino.h>
#include <nahs-Bricks-OS.h>
// include all features of brick
#include <nahs-Bricks-Feature-Signal.h>
#include <nahs-Bricks-Feature-Bat.h>
#include <nahs-Bricks-Feature-Sleep.h>

void setup() {
  // Now register all the features under All
  // Note: the order of registration is the same as the features are handled internally by FeatureAll
  FeatureAll.registerFeature(&FeatureSignal);
  FeatureAll.registerFeature(&FeatureBat);
  FeatureAll.registerFeature(&FeatureSleep);

  // Set Brick-Specific stuff
  BricksOS.setSetupPin(D5);
  FeatureAll.setBrickType(3);

  // Set Brick-Specific (feature related) stuff
  Wire.begin();
  Expander.begin(45);
  FeatureSignal.assignExpanderPin(Expander, 0);
  FeatureSignal.assignExpanderPin(Expander, 1);
  FeatureSignal.assignExpanderPin(Expander, 2);
  FeatureBat.setPins(D6, D7, A0);

  // Finally hand over to BrickOS
  BricksOS.handover();
}

void loop() {
  // Not used on Bricks
}