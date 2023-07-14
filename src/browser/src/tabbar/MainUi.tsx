import React from 'react';
import TabManager from '../browserprops/TabManager';
import { Context } from '../Context';
import Tab from '@src/browserprops/Tab';
import "./MainUi.css"

const TabBar: React.FC = () => {
    const [tabs, setTabs] = React.useState<Tab[]>([]);
    const [tabSize, setTabtabSize] = React.useState<number>(20)
    const [search, setSearch] = React.useState<string>("");
    const tabManager = React.useContext(Context)[1] as TabManager;

    React.useEffect(() => {
        console.log("TabBar: useEffect");
        setTabs(tabManager.getTabs);
    }, []);

    React.useEffect(() => {
        var screenWidth = window.innerWidth
        var tabCount = tabs.length
        if (tabCount === 0) {
            tabCount = 1
        }
        console.log("TabBar: screenWidth: ", screenWidth);
        var tabWidth = (screenWidth - (screenWidth * 0.1)) / tabCount
        setTabtabSize(tabWidth)
    }, [tabs])

    console.log("TabBar: ", tabs);

    const handleChange = (e: any) => {
        setSearch(e.target.value);
    };

    const loadFunction = () => {
        console.log("TabBar: loadFunction");
        tabManager.setActiveTab = tabManager.getTabs[0].md5hash;
    }

    React.useEffect(() => {
        console.log("TabBar: useEffect");
        loadFunction();
    }, []);

    return (
        <div className='browser-internal-body'>
            <div className='browser-internal-tab-container'>
                {tabs.map((tab: Tab) => (
                    <div key={tab.title} id={tab.md5hash}>
                        {tab.active == true ?
                            <button className="browser-internal-tab browser-internal-active" id={tab.md5hash} style={{maxWidth: 200, width: tabSize}}>{tab.title}</button>
                            :
                            <button className="browser-internal-tab"  id={tab.md5hash} style={{maxWidth: 200, width: tabSize}}>{tab.title}</button>
                        }
                    </div>
                ))}
            </div>
            <div className="browser-internal-search-container">
                <input type="text" className="browser-internal-search-bar" value={search} onChange={handleChange}></input>
            </div>
            {tabs.map((tab: Tab) => (
                <div key={tab.title} id={tab.md5hash}>
                    <iframe className="browser-internal-page" id={tab.md5hash} src={"html://" + tab.md5hash + "/index.html"}></iframe>
                </div>
            ))}
        </div>
    );
}

export default TabBar;
