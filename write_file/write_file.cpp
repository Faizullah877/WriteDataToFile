#include <iostream>
#include <fstream>
#include <string>

bool db_write_file_bitstream(const std::string& filename, const unsigned char* const data, const unsigned long int data_size) {
    try {
        // Open the file in binary mode for writing
        std::ofstream file(filename, std::ios::out | std::ios::binary);
        if (!file.is_open()) {
            std::cerr << "Error opening file: " << filename << std::endl;
            return false;
        }

        // Write the data to the file
        file.write(reinterpret_cast<const char*>(data), static_cast<std::streamsize>(data_size));

        // Check if writing was successful
        if (!file.good()) {
            std::cerr << "Error occurred while writing data to file: " << filename << std::endl;
            return false;
        }

        // Close the file
        file.close();

        return true; // Data successfully written
    }
    catch (const std::exception& e) {
        std::cerr << "Exception occurred: " << e.what() << std::endl;
        return false;
    }
}

int main() {
    // Example usage
    const std::string filename = "example.bin";
    const unsigned char data[] = { 0x41, 0x42, 0x43 }; // Example data
    const unsigned long long int data_size = sizeof(data);

    if (db_write_file_bitstream(filename, data, data_size)) {
        std::cout << "Data written successfully to file: " << filename << std::endl;
    }
    else {
        std::cerr << "Failed to write data to file: " << filename << std::endl;
    }

    return 0;
}
