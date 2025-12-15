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
#include <wsjcpp_core.h>

WsjcppUserSession::WsjcppUserSession() {
  TAG = "WsjcppUserSession";
  m_nUserID = -1;
  m_sRole = "";
  m_sEmail = "";
  m_sNickName = "";
  m_sUserUuid = "";
}

WsjcppUserSession::WsjcppUserSession(const nlohmann::json &obj) : WsjcppUserSession() {
  std::string sError;
  if (!this->fillFrom(obj, sError)) {
    WsjcppLog::err(TAG, sError);
  }
}

bool WsjcppUserSession::fillFrom(const nlohmann::json &obj, std::string &sError) {
  bool bResult = true;
  if (obj.find("user") != obj.end()) {
    nlohmann::json user = obj.at("user");

    // user.role
    try {
      m_sRole = user.at("role").get<std::string>();
    } catch (const std::exception &e) {
      // WsjcppLog::err(TAG, "JSON: " + obj.dump());
      // WsjcppLog::err(TAG, "Something wrong param user.role in struct. " + std::string(e.what()));
      sError = "Something wrong param user.role in struct. " + std::string(e.what());
      m_sRole = "";
      bResult = false;
    }

    // TODO check allow roles

    // user.id
    try {
      m_nUserID = user.at("id").get<int>();
    } catch (const std::exception &e) {
      // WsjcppLog::err(TAG, "JSON: " + obj.dump());
      // WsjcppLog::err(TAG, "Something wrong param user.id in struct. " + std::string(e.what()));
      if (sError.size() > 0) sError += "\n";
      sError += "Something wrong param user.id in struct. " + std::string(e.what());
      m_nUserID = -1;
      bResult = false;
    }

    // user.email
    try {
      m_sEmail = user.at("email").get<std::string>();
    } catch (const std::exception &e) {
      // WsjcppLog::err(TAG, "JSON: " + obj.dump());
      // WsjcppLog::err(TAG, "Something wrong param user.email in struct. " + std::string(e.what()));
      if (sError.size() > 0) sError += "\n";
      sError += "Something wrong param user.email in struct. " + std::string(e.what());
      m_sEmail = "";
      bResult = false;
    }

    // user.nick
    try {
      m_sNickName = user.at("nick").get<std::string>();
    } catch (const std::exception &e) {
      // WsjcppLog::err(TAG, "JSON: " + obj.dump());
      // WsjcppLog::err(TAG, "Something wrong param user.nick in struct. " + std::string(e.what()));
      if (sError.size() > 0) sError += "\n";
      sError += "Something wrong param user.nick in struct. " + std::string(e.what());
      m_sNickName = "";
      bResult = false;
    }

    // user.uuid
    try {
      m_sUserUuid = user.at("uuid").get<std::string>();
    } catch (const std::exception &e) {
      // WsjcppLog::err(TAG, "JSON: " + obj.dump());
      // WsjcppLog::err(TAG, "Something wrong param user.uuid in struct. " + std::string(e.what()));
      if (sError.size() > 0) sError += "\n";
      sError += "Something wrong param user.uuid in struct. " + std::string(e.what());
      m_sUserUuid = "";
      bResult = false;
    }
  } else {
    sError = "Not found param 'user' in struct";
    bResult = false;
  }
  return bResult;
}

nlohmann::json WsjcppUserSession::toJson() {
  nlohmann::json userInfo;
  userInfo["role"] = m_sRole;
  userInfo["nick"] = m_sNickName;
  userInfo["email"] = m_sEmail;
  userInfo["id"] = m_nUserID;
  userInfo["uuid"] = m_sUserUuid;
  nlohmann::json sessionInfo;
  sessionInfo["user"] = userInfo;
  return sessionInfo;
}

void WsjcppUserSession::setRole(const std::string& role) { m_sRole = role; }

std::string WsjcppUserSession::role() const { return m_sRole; }

bool WsjcppUserSession::isAdmin() const { return m_sRole == "admin"; }

bool WsjcppUserSession::isUser() const { return m_sRole == "user"; }

bool WsjcppUserSession::isTester() const { return m_sRole == "tester"; }

bool WsjcppUserSession::hasRole() const { return m_sRole != ""; }

void WsjcppUserSession::setNick(const std::string &sNickName) { m_sNickName = sNickName; }

std::string WsjcppUserSession::nick() const { return m_sNickName; }

void WsjcppUserSession::setEmail(const std::string& sEmail) { m_sEmail = sEmail; }

std::string WsjcppUserSession::email() const { return m_sEmail; }

void WsjcppUserSession::setUserId(int nUserId) { m_nUserID = nUserId; }

int WsjcppUserSession::userid() const { return m_nUserID; }

void WsjcppUserSession::setUserUuid(const std::string& sUserUuid) { m_sUserUuid = sUserUuid; }

std::string WsjcppUserSession::userUuid() const { return m_sUserUuid; }
