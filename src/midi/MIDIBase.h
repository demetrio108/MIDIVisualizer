#ifndef MIDI_BASE_H
#define MIDI_BASE_H

#include "MIDIUtils.h"

struct MIDINote {

	MIDINote(short aNote, double aStart, double aDuration, short aVelocity, short aChannel);

	void print() const;

	double start;
	double duration;
	short note;
	short velocity;
	short channel;
};

struct MIDIEvent {

	MIDIEvent(EventCategory aCategory, uint8_t aType, size_t aDelta, std::vector<short> aData);

	void print() const;

	static MIDIEvent readMIDIEvent(const std::vector<char> & buffer, size_t & position, size_t delta, uint8_t & previousFirstByte);

	static MIDIEvent readMetaEvent(const std::vector<char> & buffer, size_t & position, size_t delta);

	static MIDIEvent readSysexEvent(const std::vector<char> & buffer, size_t & position, size_t delta);

	EventCategory category;
	uint8_t type;
	size_t delta;
	std::vector<short> data;

};

struct MIDITempo {

	MIDITempo();

	MIDITempo(size_t astart, uint atempo);

	void print() const;

	size_t start = 0;
	uint tempo = 0;
	double timestamp = 0.0;
};

struct ActiveNoteInfos {
	float start = 1000000.0f;
	float duration = 0.0f;
	bool enabled = false;
};

#endif // MIDI_BASE_H