//
// Created by f4ls3 on 12.11.2022.
//

#pragma once

namespace Forge {
    class Controller {
    private:
        /*bool buttons[];
        float axes[];*/
    };

    class InputManager {
    public:
        /*const Controller *get_connected_controllers() const {
            return connected_controllers;
        }*/
    private:
        //Controller connected_controllers[];
    };

    class KeybindManager {

    };

    enum InputType {
        AXIS,
        BUTTON
    };

    class Keybind {
    public:
        const std::string *get_name() const {
            return &name;
        }

        const InputType *get_input_type() const {
            return &input_type;
        }

        const int *getBindings() const {
            return bindings;
        }

    private:
        std::string name;
        InputType input_type;
        int bindings[];
    };
}