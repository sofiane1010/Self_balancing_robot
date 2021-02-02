class Stepper{
    private:
        int dirPin;
        int stepPin;
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
        Stepper(int dirPin, int stepPin);
        void run();
        void setSpeed(int stepPerSec);
        int currentPosition();
        void setCurrentPosition(int newPosition);
        void moveTo(int targetPosition);
        void setMaxSpeed(int maxStepPerSec);
        void setAcceleration(int accel);
        void setCurrentSpeed();
};