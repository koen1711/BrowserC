import Communication from "@src/Comms";
import Tab from "./Tab";


class TabManager {

    private tabs: Tab[] = [];
    private activeTab: Tab;
    private  comms: Communication;

    constructor(Comms: Communication) {
        this.comms = Comms;
        console.log(this.getTabs);
    }

    private loadTabsFromJson(json: string) {
        this.tabs = [];
        if (json == "") {
            this.tabs = [ new Tab("https://www.google.com", "Google", "") ];
            this.tabs[0].active = true;
        }
        else {
            var jsonTabs = JSON.parse(json);
            for (var i = 0; i < jsonTabs.length; i++) {
                var tab = new Tab(jsonTabs[i].url, jsonTabs[i].title, jsonTabs[i].md5);
                this.tabs.push(tab);
            }
            this.tabs[0].active = true;

        }
    }

    get getTabs(): Tab[] {
        this.loadTabsFromJson(this.comms.getTabs);
        return this.tabs;
    }

    set setActiveTab(md5: string) {
        for (var i = 0; i < this.tabs.length; i++) {
            if (this.tabs[i].md5hash == md5) {
                this.tabs[i].active = true;
                this.activeTab = this.tabs[i];
            }
            else {
                this.tabs[i].active = false;
            }
        }

    }
}

export default TabManager;