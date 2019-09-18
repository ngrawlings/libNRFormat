//
//  main.cpp
//  UnitTests
//
//  Created by Nyhl Rawlings on 17/09/2019.
//  Copyright © 2019 Liquidsoft Studio. All rights reserved.
//

#include <iostream>
#include "../nrformat/Json.h"
#include <libnrcore/memory/String.h>

#include <libnrdebug/UnitTests.h>

using namespace nrcore;

int main(int argc, const char * argv[]) {
    // insert code here...
    String _json("{\"params\":{\"processed\":\"0\",\"window_id\":\"1\"},\"command\":\"Task\",\"hash\":\"B1\", \"results\": {\"processed\":\"100\"}, \"number\":555}");
    
    Json json(_json);
    String params = json.getString("params");
    printf("%s\n", params.operator char *());
    
    params = json.getString("command");
    printf("%s\n", params.operator char *());
    
    params = json.getString("hash");
    printf("%s\n", params.operator char *());
    
    params = json.getString("results");
    printf("%s\n", params.operator char *());
    
    params = json.getString("number");
    printf("%s\n", params.operator char *());
    
    return 0;
}
