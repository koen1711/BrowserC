import React from 'react';
import TabManager from '../browserprops/TabManager';
import { Context } from '../Context';
import Tab from '@src/browserprops/Tab';
import "./MainUi.css"

const TabBar: React.FC = () => {
    const [tabs, setTabs] = React.useState<Tab[]>([]);
    const [search, setSearch] = React.useState<string>("");
    const tabManager = React.useContext(Context)[1] as TabManager;

    React.useEffect(() => {
        console.log("TabBar: useEffect");
        setTabs(tabManager.getTabs);
    }, []);

    console.log("TabBar: ", tabs);

    const handleChange = (e: any) => {
        setSearch(e.target.value);
    };

    return (
        <div className='browser-internal-body'>
            <div className='browser-internal-tab-container'>
                {tabs.map((tab: Tab) => (
                    <div key={tab.title}>
                        <button className="browser-internal-tab" id={tab.md5hash}>{tab.title}</button>
                    </div>
                ))}
            </div>
            <div className="browser-internal-search-container">
                <form className="browser-internal-search-bar" style={{color: 'red'}}>
                    <input type="text" style={{color: 'red'}} value={search} onChange={handleChange}></input>
                </form>
            </div>
        </div>
    );
}

export default TabBar;
