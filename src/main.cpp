#include <string.h>
#include <iostream>
#include <algorithm>
#include <wsjcpp_core.h>
#include <wsjcpp_user_session.h>

int main(int argc, const char* argv[]) {
    std::string TAG = "MAIN";
    std::string appName = std::string(WSJCPP_APP_NAME);
    std::string appVersion = std::string(WSJCPP_APP_VERSION);
    if (!WsjcppCore::dirExists(".logs")) {
        WsjcppCore::makeDir(".logs");
    }
    WsjcppLog::setPrefixLogFile("wsjcpp");
    WsjcppLog::setLogDirectory(".logs");

    WsjcppUserSession session;

    nlohmann::json userInfo;
    userInfo["role"] = "admin";
    userInfo["nick"] = "Bug-man";
    userInfo["email"] = "admin@admin.com";
    userInfo["id"] = 55534;
    userInfo["uuid"] = "1312ba96-f9e0-49cd-89ba-6e07794e1ea1";
    nlohmann::json sessionInfo;
    sessionInfo["user"] = userInfo;

    std::string sError = "";
    if (!session.fillFrom(sessionInfo, sError)) {
        WsjcppLog::err(TAG, sError);
        return -1;
    }

    if (session.isAdmin()) {
        WsjcppLog::info(TAG, "user is admin with nickname " + session.nick());
    }

    return 0;
}

