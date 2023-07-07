import Communication from "@src/Comms";
import Tab from "./Tab";


class TabManager {

    private tabs: Tab[] = [];


    constructor(Comms: Communication) {
        this.loadTabsFromJson("[]");
    }

    private loadTabsFromJson(json: string) {
        if (json == "") {
            this.tabs = [ new Tab("New Tab", "https://www.google.com", "") ];
        }
        this.tabs = JSON.parse(json);
    }

    get getTabs(): Tab[] {
        this.tabs = JSON.parse(`[{"url":"https://www.google.com","md5":"8ffdefbdec956b595d257f0aaeefd623"}]`);
        return this.tabs;
    }
}

export default TabManager;