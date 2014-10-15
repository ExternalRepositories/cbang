/******************************************************************************\

          This file is part of the C! library.  A.K.A the cbang library.

              Copyright (c) 2003-2014, Cauldron Development LLC
                 Copyright (c) 2003-2014, Stanford University
                             All rights reserved.

        The C! library is free software: you can redistribute it and/or
        modify it under the terms of the GNU Lesser General Public License
        as published by the Free Software Foundation, either version 2.1 of
        the License, or (at your option) any later version.

        The C! library is distributed in the hope that it will be useful,
        but WITHOUT ANY WARRANTY; without even the implied warranty of
        MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
        Lesser General Public License for more details.

        You should have received a copy of the GNU Lesser General Public
        License along with the C! library.  If not, see
        <http://www.gnu.org/licenses/>.

        In addition, BSD licensing may be granted on a case by case basis
        by written permission from at least one of the copyright holders.
        You may request written permission by emailing the authors.

                For information regarding this software email:
                               Joseph Coffland
                        joseph@cauldrondevelopment.com

\******************************************************************************/

#include "GoogleOAuth2.h"

#include <cbang/net/URI.h>
#include <cbang/config/Options.h>

using namespace cb;
using namespace std;


GoogleOAuth2::GoogleOAuth2(Options &options, const string &maxAuthAge) :
  maxAuthAge(maxAuthAge) {
  authURL = "https://accounts.google.com/o/oauth2/auth";
  tokenURL = "https://accounts.google.com/o/oauth2/token";

  options.pushCategory("Google OAuth2 Login");
  OAuth2::addOptions(options, "google-");
  options.popCategory();
}


URI GoogleOAuth2::getRedirectURL(const string &path, const string &state,
                                 const string &scope) const {
  URI url = OAuth2::getRedirectURL(path, state, scope);
  if (!maxAuthAge.empty()) url.set("max_auth_age", maxAuthAge);
  return url;
}

