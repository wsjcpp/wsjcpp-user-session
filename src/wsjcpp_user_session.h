/**********************************************************************************
 * MIT License
 *
 * Copyright (c) 2025 wsjcpp
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
 ***********************************************************************************/

#pragma once

#include <string>
#include <nlohmann/json.hpp>

class WsjcppUserSession {
public:
  WsjcppUserSession();
  WsjcppUserSession(const nlohmann::json &obj);
  bool fillFrom(const nlohmann::json &obj, std::string &sError);
  nlohmann::json toJson();

  void setRole(const std::string& role);
  std::string role() const;

  // TODO extending roles somehow
  bool isAdmin() const;
  bool isUser() const;
  bool isTester() const;
  bool hasRole() const;
  void setNick(const std::string &sNickName);
  std::string nick() const;
  void setEmail(const std::string& sEmail);
  std::string email() const;
  void setUserId(int nUserId);
  int userid() const;
  void setUserUuid(const std::string& sUserUuid);
  std::string userUuid() const;
  // TODO json field for customization

private:
  std::string m_sRole;
  std::string m_sEmail;
  std::string m_sNickName;
  int m_nUserID;
  std::string m_sUserUuid;
  std::string TAG;
};