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

 #include "wsjcpp_user_session.h"


WsjcppUserSession::WsjcppUserSession() {
  TAG = "WsjcppUserSession";
  m_nUserID = -1;
  m_sRole = "";
  m_sEmail = "";
  m_sNick = "";
  m_sUserUuid = "";
}

WsjcppUserSession::WsjcppUserSession(nlohmann::json const &obj) : WsjcppUserSession() {
    this->fillFrom(obj);
}

void WsjcppUserSession::fillFrom(const nlohmann::json &obj) {
  if (obj.find("user") != obj.end()) {
    nlohmann::json user = obj.at("user");

    // user.role
    try {
      m_sRole = user.at("role").get<std::string>();
    } catch (const std::exception &e) {
      WsjcppLog::err(TAG, "JSON: " + obj.dump());
      WsjcppLog::err(TAG, "Something wrong param user.role in struct. " + std::string(e.what()));
      m_sRole = "";
    }

    // TODO check allow roles

    // user.id
    try {
      m_nUserID = user.at("id").get<int>();
    } catch (const std::exception &e) {
      WsjcppLog::err(TAG, "JSON: " + obj.dump());
      WsjcppLog::err(TAG, "Something wrong param user.id in struct. " + std::string(e.what()));
      m_nUserID = -1;
    }

    // user.email
    try {
      m_sEmail = user.at("email").get<std::string>();
    } catch (const std::exception &e) {
      WsjcppLog::err(TAG, "JSON: " + obj.dump());
      WsjcppLog::err(TAG, "Something wrong param user.email in struct. " + std::string(e.what()));
      m_sEmail = "";
    }

    // user.nick
    try {
      m_sNick = user.at("nick").get<std::string>();
    } catch (const std::exception &e) {
      WsjcppLog::err(TAG, "JSON: " + obj.dump());
      WsjcppLog::err(TAG, "Something wrong param user.nick in struct. " + std::string(e.what()));
      m_sNick = "";
    }

    // user.uuid
    try {
      m_sUserUuid = user.at("uuid").get<std::string>();
    } catch (const std::exception &e) {
      WsjcppLog::err(TAG, "JSON: " + obj.dump());
      WsjcppLog::err(TAG, "Something wrong param user.uuid in struct. " + std::string(e.what()));
      m_sUserUuid = "";
    }

  } else {
    WsjcppLog::warn(TAG, "Not found param 'user' in struct");
  }
}

bool WsjcppUserSession::isAdmin() { return m_sRole == "admin"; }

bool WsjcppUserSession::isUser() { return m_sRole == "user"; }

bool WsjcppUserSession::isTester() { return m_sRole == "tester"; }

bool WsjcppUserSession::hasRole() { return m_sRole != ""; }

std::string WsjcppUserSession::nick() { return m_sNickname; }

void WsjcppUserSession::setNick(QString sNick) { m_sNick = sNick.toStdString(); }

int WsjcppUserSession::userid() { return m_nUserID; }

std::string WsjcppUserSession::userUuid() { return m_sUserUuid; }

std::string WsjcppUserSession::email() { return m_sEmail; }
