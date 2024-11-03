/**
* @file FileUtils.cpp
* @author Hudson Schumaker
* @brief Implements the FileUtils class
* @version 1.0.0
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* @copyright Copyright (c) 2024, Dodoi-Lab
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/
#include "FileUtils.h"

std::string FileUtils::getClearName(std::filesystem::path file) {
    return file.stem().string();
}

std::string FileUtils::getClearName(const std::string path) {
    return getClearName(std::filesystem::path(path));
}

std::string FileUtils::getName(const std::string path) {
    std::filesystem::path file(path);
    return file.filename().string();
}

std::string FileUtils::getClearPath(const std::string path) {
    std::size_t pos = path.find_last_of(std::filesystem::path::preferred_separator);
    return path.substr(0, pos + 1);
}

std::string FileUtils::getFileExtension(std::filesystem::path file) {
    return getFileExtension(file.string());
}

std::string FileUtils::getFileExtension(const std::string fileName) {
    std::size_t pos = fileName.find_last_of(".");
    if (pos != std::string::npos) {
        return fileName.substr(pos + 1);
    }
    return "";
}

std::vector<std::string> FileUtils::listImageFilesInFolder() {
    const std::set<std::string> imageExtensions = {".jpg", ".jpeg", ".png", ".bmp", ".gif"};
    return listFilesInFolder(IMAGE_FOLDER, imageExtensions);
}

std::vector<std::string> FileUtils::listAudioFilesInFolder() {
    const std::set<std::string> soundExtensions = {".mp3", ".wav", ".ogg"};
    return listFilesInFolder(AUDIO_FOLDER, soundExtensions);
}

std::vector<std::string> FileUtils::listFontFilesInFolder() {
    const std::set<std::string> fontExtensions = {".ttf"};
    return listFilesInFolder(FONT_FOLDER, fontExtensions);
}

std::vector<std::string> FileUtils::listMapFilesInFolder() {
    const std::set<std::string> mapExtensions = {".map"};
    return listFilesInFolder(MAP_FOLDER, mapExtensions);
}

std::vector<std::string> FileUtils::listFilesInFolder(const std::filesystem::path dirPath, const std::set<std::string> &extensions) {
    std::vector<std::string> fileNames;

    for (const auto &entry : std::filesystem::directory_iterator(dirPath)) {
        if (entry.is_regular_file()) {
            std::string extension = entry.path().extension().string();
            if (extensions.find(extension) != extensions.end()) {
                fileNames.push_back(entry.path().filename().string());
            }
        }
    }

    return fileNames;
}
