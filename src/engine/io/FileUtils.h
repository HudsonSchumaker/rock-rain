/**
* @file FileUtils.h
* @author Hudson Schumaker
* @brief Implements FileUtils class.
* @version 1.0.0
* @date 2024-03-01
*
* Dodoi-Engine is a game engine developed by Dodoi-Lab.
* This file contains the FileUtils class, which is a utility class for file operations.
* It provides static functions for various file operations such as getting file names, paths, extensions, and listing files in a folder.
*
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
#pragma once
#include "../../Pch.h"

/**
* @class FileUtils
* @brief A utility class for file operations.
*/
class FileUtils final {
public:
    /**
    * @brief Get the clear name of a file.
    *
    * @param file The file path.
    * @return The clear name of the file.
    *
    * Input: "/path/to/file.txt" <br>
    * Output: "file"
    */
    static std::string getClearName(std::filesystem::path file);

    /**
    * @brief Get the clear name of a file.
    *
    * @param path The file path.
    * @return The clear name of the file.
    *
    * Input: "/path/to/file.txt"
    * Output: "file"
    */
    static std::string getClearName(const std::string path);

    /**
    * @brief Get the name of a file.
    *
    * @param path The file path.
    * @return The name of the file.
    *
    * Input: "/path/to/file.txt" <br>
    * utput: "file.txt"
    */
    static std::string getName(const std::string path);

    /**
    * @brief Get the clear path of a file.
    *
    * @param path The file path.
    * @return The clear path of the file.
    *
    * Input: "/path/to/file.txt" <br>
    * Output: "/path/to"
    */
    static std::string getClearPath(const std::string path);

    /**
    * @brief Get the extension of a file.
    *
    * @param file The file path.
    * @return The extension of the file.
    *
    * Input: "/path/to/file.txt" <br>
    * Output: ".txt"
    */
    static std::string getFileExtension(std::filesystem::path file);

    /**
    * @brief Get the extension of a file.
    *
    * @param fileName The file name.
    * @return The extension of the file.
    *
    * Input: "file.txt"
    * Output: ".txt"
    */
    static std::string getFileExtension(const std::string fileName);

    /**
    * @brief List the image files in a folder.
    *
    * @return A vector of image file names.
    *
    * Input: None (assumes current directory) <br>
    * Output: {"image1.png", "image2.jpg", ...}
    */
    static std::vector<std::string> listImageFilesInFolder();

    /**
    * @brief List the audio files in a folder.
    *
    * @return A vector of audio file names.
    *
    * Input: None (assumes current directory) <br>
    * Output: {"audio1.mp3", "audio2.wav", ...}
    */
    static std::vector<std::string> listAudioFilesInFolder();

    /**
    * @brief List the font files in a folder.
    *
    * @return A vector of font file names.
    *
    * Input: None (assumes current directory)
    * Output: {"font1.ttf", "font2.otf", ...}
    */
    static std::vector<std::string> listFontFilesInFolder();

    /**
    * @brief List the map files in a folder.
    *
    * @return A vector of map file names.
    *
    * Input: None (assumes current directory) <br>
    * Output: {"map1.map", "map2.map", ...}
    */
    static std::vector<std::string> listMapFilesInFolder();

    /**
    * @brief List the files in a folder with specific extensions.
    *
    * @param dirPath The directory path.
    * @param extensions The set of file extensions to filter by.
    * @return A vector of file names with the specified extensions.
    *
    * Input: ("/path/to", {".txt", ".docx"}) <br>
    * Output: {"file1.txt", "file2.docx", ...}
    */
    static std::vector<std::string> listFilesInFolder(const std::filesystem::path dirPath, const std::set<std::string>& extensions);
};
