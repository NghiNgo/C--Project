# About Search Engine Project:

Most academic institutions, colleges and universities, have their own websites that provide information regarding students’ research papers, project source codes and project reports. These records can be used as a reference by new students entering the colleges and universities. This search engine provides a platform to find out such records, information and data that can help students in the academic works.

This C++ Search Engine Project supports two basic search engines: Google Scholar and Microsoft Academic Scholar. Compared to Microsoft Academic Search, the search base of Google Scholar is large. Also, the project includes combined engine: Google Scholar cum Microsoft Academic Scholar along with two fake search engines: Single Test Search and Combined Double Test Search.

The list of search engines in this project are outlined below. The last two engines simply response with random search results waiting random time.

- Google Scholar

- Microsoft Academic Search

- Google Scholar cum Microsoft Academic Search

- Single Test Search Engine

- Fake Test Combined Double Search

**Search Modes:**

Also, this Search Engine project in C++ features three different search modes. These are listed below; the mode of search is detected automatically by the system and is dependent on request.

- Single Person + Single Search Engine

- Single Person + Multiple Search Engines

- Multiple Users + Multiple Search Engines

For each of these modes, the program generates one thread. So, when the last mode is used, i.e. when multiple users use the search engine application, the program generates one thread for every user. Also, the program maintains one minute search timeout for each task.

In case of Single Person + Single Search Engine mode, graph of articles is generated with approximation. Multiple names can be searched by using new line separated option. For each search query, count of articles can be displayed. The displayed search results can be saved using save option in JSON format.
