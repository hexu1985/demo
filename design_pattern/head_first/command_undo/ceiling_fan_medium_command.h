#ifndef __ceiling_fan_medium_command_h
#define __ceiling_fan_medium_command_h

#include <memory>
#include "command.h"
#include "ceiling_fan.h"

class CeilingFanMediumCommand: public Command {
private:
    std::shared_ptr<CeilingFan> ceilingFan;
    int prevSpeed;

public:
	CeilingFanMediumCommand(std::shared_ptr<CeilingFan> ceilingFan): ceilingFan(ceilingFan) {
	}

	void execute() override {
        prevSpeed = ceilingFan->getSpeed();
		ceilingFan->medium();
	}

    void undo() override {
        switch (prevSpeed) {
            case CeilingFan::HIGH:   ceilingFan->high(); break;
            case CeilingFan::MEDIUM: ceilingFan->medium(); break;
            case CeilingFan::LOW:    ceilingFan->low(); break;
            default:                 ceilingFan->off(); break;
        }        
    }
};

#endif
