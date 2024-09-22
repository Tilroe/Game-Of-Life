#pragma once


void allocate_hip_memory(const int width, const int height);
void free_hip_memory();
void game_of_life_global(int* in, int* out, const int width, const int height);