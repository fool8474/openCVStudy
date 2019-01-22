#pragma once

void put_string(cv::Mat & frame, std::string text, cv::Point pt, int value);

void helloVideo();

void zoom_bar(int value, void *);

void focus_bar(int value, void *);

void setCamera();

void adjustVideoFile();
