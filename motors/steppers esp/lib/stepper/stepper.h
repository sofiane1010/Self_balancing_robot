class Stepper{
    private:
        int dirPin;
        int stepPin;
        float periode;
        float minPeriode;
        int currentPos;
        int targetPosition;
        

    public:
        Stepper(int dirPin, int stepPin);
        void run();
        void setSpeed(int stepPerSec);
        int currentPosition();
        void setCurrentPosition(int newPosition);
        void moveTo(int targetPosition);
        void setMaxSpeed(int maxStepPerSec);
};