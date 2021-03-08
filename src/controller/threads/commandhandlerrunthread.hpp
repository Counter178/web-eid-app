/*
 * Copyright (c) 2020 The Web eID Project
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#pragma once

#include "controllerchildthread.hpp"

class CommandHandlerRunThread : public ControllerChildThread
{
    Q_OBJECT

public:
    CommandHandlerRunThread(QObject* parent, CommandHandler& handler,
                            electronic_id::CardInfo::ptr c) :
        ControllerChildThread(parent),
        commandHandler(handler), cmdType(commandHandler.commandType()), card(c)
    {
    }

private:
    void doRun() override { commandHandler.run(card); }

    const std::string& commandType() const override { return cmdType; }

    CommandHandler& commandHandler;
    const std::string cmdType;
    electronic_id::CardInfo::ptr card;
};
