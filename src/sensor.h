#include <Arduino.h>

enum sensorType { digital, analog, dummy };

//template <class T>
class sensor 
{
private:
    int m_pin;
    sensorType m_type;
    int m_data;
public:
    sensor(int pin, sensorType type);
    void initialize();
    int readRaw();
};

//template <class T>
sensor::sensor(int pin, sensorType type)
{
    m_pin = pin;
    m_type = type;
    m_data = -1;
}


//template <class T>
void sensor::initialize()
{
    pinMode(m_pin, INPUT);
}

//template <class T>
int sensor::readRaw()
{   
    switch (m_type)
    {
    case digital:
        return digitalRead(m_pin);
        break;
    case analog:
        return analogRead(m_pin);
        break;
    case dummy:
        return m_data++; 
        break;
    default:
        return -1;
        break;
    }
}

// Sensors to be used:
//  Voltage (V)
//  Current (A)
//  Water Flow ()
//  Temperature (C)