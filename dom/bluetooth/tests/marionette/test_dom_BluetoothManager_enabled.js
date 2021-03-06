/* -*- Mode: C++; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 2 -*-
 * vim: sw=2 ts=2 sts=2 et filetype=javascript
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

MARIONETTE_TIMEOUT = 60000;
MARIONETTE_HEAD_JS = 'head.js';

function waitEitherEnabledOrDisabled() {
  let deferred = Promise.defer();

  function onEnabledDisabled(aEvent) {
    bluetoothManager.removeEventListener("enabled", onEnabledDisabled);
    bluetoothManager.removeEventListener("disabled", onEnabledDisabled);

    ok(true, "Got event " + aEvent.type);
    deferred.resolve(aEvent.type === "enabled");
  }

  bluetoothManager.addEventListener("enabled", onEnabledDisabled);
  bluetoothManager.addEventListener("disabled", onEnabledDisabled);

  return deferred.promise;
}

function test(aEnabled) {
  log("Testing 'bluetooth.enabled' => " + aEnabled);

  let deferred = Promise.defer();

  Promise.all([setBluetoothEnabled(aEnabled),
               waitEitherEnabledOrDisabled()])
    .then(function(aResults) {
      /* aResults is an array of two elements:
       *   [ <result of setBluetoothEnabled>,
       *     <result of waitEitherEnabledOrDisabled> ]
       */
      log("  Examine results " + JSON.stringify(aResults));

      is(bluetoothManager.enabled, aEnabled, "bluetoothManager.enabled");
      is(aResults[1], aEnabled, "'enabled' event received");

      if (bluetoothManager.enabled === aEnabled && aResults[1] === aEnabled) {
        deferred.resolve();
      } else {
        deferred.reject();
      }
    });

  return deferred.promise;
}

startBluetoothTestBase(["settings-read", "settings-write"],
                       function testCaseMain() {
  return getBluetoothEnabled()
    .then(function(aEnabled) {
      log("Original 'bluetooth.enabled' is " + aEnabled);
      // Set to !aEnabled and reset back to aEnabled.
      return test(!aEnabled).then(test.bind(null, aEnabled));
    });
});
