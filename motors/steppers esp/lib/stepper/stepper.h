#include <string.h>

class Stepper{
    private:
        int dirPin1;
        int stepPin1;
        int dirPin2;
        int stepPin2;
        int currentPos;
        int targetPosition;
        int currentSpeed;
        int acceleration;
        int accelInterval;
        float finalPeriode;
        float initialPeriode;
        float currentPeriode;
        float minPeriode;

    public:
        Stepper(int dirPin1, int stepPin1, int dirPin2, int stePin2);
        void run();
        void setSpeed(int stepPerSec);
        int currentPosition();
        void setCurrentPosition(int newPosition);
        void moveTo(int targetPosition, std::string runMode);
        void setMaxSpeed(int maxStepPerSec);
        void setAcceleration(int accel);
        void setCurrentSpeed();
};