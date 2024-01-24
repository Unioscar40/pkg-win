#pragma once

#include <string>
#include <string_view>
#include <vector>
#include <filesystem>

using Byte = unsigned char;

using ByteBuffer = std::vector<Byte>;

using StringView = std::string_view;

using String = std::string;

using FilesystemPath = std::filesystem::path;