#include "SoundManager.h"

#include <iostream>

bool SoundManager::load(const char* fileName, std::string id, int type) {
	//type1 => music, type0 => sfx
	if (type == 1) { // Music
		Mix_Music* music = Mix_LoadMUS(fileName);

		if (music == 0) {
			std::cout << "Could not load music " << Mix_GetError() << std::endl;
			return false;
		}

		s_mMusic[id] = music;

		return true;
	}
	else {
		if (type == 0) { // SFX
			Mix_Chunk* chunk = Mix_LoadWAV(fileName);

			if (chunk == 0) {
				std::cout << "Could not load sfx " << Mix_GetError() << std::endl;
				return false;
			}

			s_mSfxs[id] = chunk;

			return true;
		}
	}

	return false;
}

void SoundManager::playSound(std::string id, int loop, int ms) {
	if (Mix_FadeInChannel(-1, s_mSfxs[id], loop, ms) == -1) {
		std::cout << Mix_GetError() << std::endl;
	}
}

void SoundManager::playMusic(std::string id, int loop, int ms) {
	if (Mix_FadeInMusic(s_mMusic[id], loop, ms) == -1) {
		std::cout << Mix_GetError() << std::endl;
	}
}

void SoundManager::changeVolume(int c) {
	int currnetVolume = Mix_VolumeMusic(-1);
	std::cout << currnetVolume << " " << Mix_VolumeMusic(-1) << std::endl;
	currnetVolume += c;
	Mix_VolumeMusic(currnetVolume);
}

void SoundManager::pauseOrPlay() {
	std::cout << "Mix_PlayingMusic: " << Mix_PlayingMusic() << std::endl;
	//std::cout << "Mix_PausedMusic: " << Mix_PausedMusic() << std::endl;
	//std::cout << "Mix_ResumeMusic: " << Mix_ResumeMusic() << std::endl;
	//Mix_PausedMusic();
	//Mix_ResumeMusic();

	if (Mix_PausedMusic() == 0) {
		Mix_PauseMusic();
	}
	else {
		Mix_ResumeMusic();
	}
}

void SoundManager::changeVolumeSfk(std::string id, int c) {
	int currentVolume = Mix_VolumeChunk(s_mSfxs[id], -1);
	currentVolume += c;
	Mix_VolumeChunk(s_mSfxs[id], currentVolume);
}

void SoundManager::setMusicPosition(double pos) {
	if (Mix_SetMusicPosition(pos) == -1) {
		std::cout << "Something failed: " << Mix_GetError() << std::endl;
	}
}

SoundManager::SoundManager() {
	if (Mix_OpenAudio(48000, AUDIO_S16SYS, 2, 4096) == -1) {
		std::cout << Mix_GetError() << std::endl;
	}
}

SoundManager* SoundManager::s_mInstance = 0;
