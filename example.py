import TogetherPE


def startupFunction(context): #passes things like: datetime, current UI, etc.
    TogetherPE.createCheckbox("Scripter", "myScriptCheckbox") #(tabName, checkboxName) returns a reference to the checkbox, but global variables shouldnt be used

def myCustomHandler(packet): #on_packet will pass a "packet" object
    if not TogetherPE.getCheckbox("Scripter", "myScriptCheckbox").isChecked():
        return
    with open("Packets.txt", 'a') as file: # Not the best way, IO blocks.
        file.write(f"[{packet.timestamp.isoformat(' ', 'seconds')}] {packet.address} -> {packet.data}")

TogetherPE.registerEvent('on_script_load', startupFunction)
TogetherPE.registerEvent("on_packet", myCustomHandler)