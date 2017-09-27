#ifndef Helper_H
#define Helper_H

#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

enum ButtonType
{
	PUSH_BUTTON = 0,
	STATE_BUTTON = 1
};

static map<string, ButtonType> ButtonTypesMap =
{
	{ "PUSH_BUTTON", PUSH_BUTTON },
	{ "STATE_BUTTON", STATE_BUTTON }
};

enum LedMode
{
	STATIC = 0,
	BLINK = 1,
	BLINKING = 2,
	FADE = 3,
	FADING = 4
};

static map<string, LedMode> LedModesMap =
{
	{ "STATIC", STATIC },
	{ "BLINK", BLINK },
	{ "BLINKING", BLINKING },
	{ "FADE", FADE },
	{ "FADING", FADING }
};

static vector<string> split(const string& str, const string& delim)
{
	vector<string> tokens;
	size_t prev = 0, pos = 0;
	do
	{
		pos = str.find(delim, prev);
		if (pos == string::npos) pos = str.length();
		string token = str.substr(prev, pos - prev);
		if (!token.empty()) tokens.push_back(token);
		prev = pos + delim.length();
	} while (pos < str.length() && prev < str.length());
	return tokens;
}

#endif

