#include <string>
#include <iostream>
#include <stdexcept>

int main(int argc, char *argv[]) {
    // parse arguments
    int id = -1;
    for (int i = 1; i < argc; ++i) {
        std::string arg(argv[i]);
        if (arg[0] == '-') {
            char argid;
            if (arg.length() >= 2 && arg[1] == '-') {
                // no switch on strings :(
                if (arg == "id") argid = 'i';
                else {
                    std::cerr << "Unknown long argument `" << arg << "'" << std::endl;
                    return 1;
                }
            } else {
                if (arg.length() != 2) {
                    std::cerr << "Invalid syntax for argument `" << arg << "'" << std::endl;
                    return 1;
                } else {
                    argid = arg[1];
                }
            }

            switch (argid) {
                case 'i':
                    if ((++i) == argc) {
                        std::cerr << "Argument `" << arg << "' requires a parameter (post ID)" << std::endl;
                        return 1;
                    }
                    try {
                        id = std::stoi(argv[i]);
                    } catch (const std::invalid_argument& e) {
                        std::cerr << "Parameter `" << argv[i] << "' for argument `" << arg <<
                            "' is not a valid number" << std::endl;
                        return 1;
                    } catch (const std::out_of_range& e) {
                        std::cerr << "Parameter `" << argv[i] << "' for argument `" << arg <<
                            "' is out of range" << std::endl;
                        return 1;
                    }
                    break;
                default:
                    std::cerr << "Unknown argument `" << arg << "'" << std::endl;
            }
        }
    }

    // validate arguments
    if (id == -1) {
        std::cerr << "Argument `-i' (post ID) is required" << std::endl;
        return 1;
    }

    std::cout << id << std::endl;

    return 0;
}
