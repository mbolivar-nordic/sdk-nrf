# Configuration Reference documentation build configuration file, pass 2.
# See nrf/doc/CMakeLists.txt for details.

import os
import sys

# Common configuration from ../config-pass-1/conf.py.
extensions = []
PASS_1_DIR = os.path.abspath(os.path.join(os.path.dirname(__file__), "..", "config-pass-1"))
PASS_1_CONF_PY = os.path.join(PASS_1_DIR, 'conf.py')
with open(PASS_1_CONF_PY) as f:
    code = compile(f.read(), PASS_1_CONF_PY, 'exec')
    exec(code)

# Add in the necessary intersphinx glue to build the DT bindings index
# pages in pass 2.
if "ZEPHYR_OUTPUT" not in os.environ:
    sys.exit("$ZEPHYR_OUTPUT environment variable undefined.")
ZEPHYR_OUTPUT = os.path.abspath(os.environ["ZEPHYR_OUTPUT"])

if "CONFIGURATION_OUTPUT" not in os.environ:
    sys.exit("$CONFIGURATION_OUTPUT environment variable undefined.")
CONFIGURATION_OUTPUT = os.path.abspath(os.environ["CONFIGURATION_OUTPUT"])
if "CONFIGURATION_RST_OUT" not in os.environ:
    sys.exit("$CONFIGURATION_RST_OUT environment variable undefined.")
CONFIGURATION_RST_OUT = os.path.abspath(
    os.environ["CONFIGURATION_RST_OUT"])

zephyr_target = os.path.relpath(ZEPHYR_OUTPUT, CONFIGURATION_OUTPUT)
zephyr_inventory = os.path.relpath(os.path.join(ZEPHYR_OUTPUT, 'objects.inv'),
                                   CONFIGURATION_RST_OUT)
intersphinx_mapping = {
    'zephyr': (zephyr_target, zephyr_inventory),
}

extensions.append('sphinx.ext.intersphinx')
