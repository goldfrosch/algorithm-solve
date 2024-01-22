function solution(id_list, report, k) {
    var answer = [];
    var reportTable = {}
    var reportedTable = {};
    
    for (var i = 0; i < id_list.length; i++) {
        reportTable[id_list[i]] = new Set();
        reportedTable[id_list[i]] = new Set();
    }
    
    for (var i = 0; i < report.length; i++) {
        var reportItem = report[i].split(' ');
        reportTable[reportItem[0]].add(reportItem[1]);
        reportedTable[reportItem[1]].add(reportItem[0]);
    }
    
    Object.keys(reportedTable).forEach((key) => {
        if (reportedTable[key].size < k) {
            delete reportedTable[key];
        }
    });
    
    for (var i = 0; i < id_list.length; i++) {
        answer[i] = 0;
        Object.keys(reportedTable).forEach((key) => {
            if (reportTable[id_list[i]].has(key)) {
                answer[i] = answer[i] + 1;
            }
        });
    }
    
    return answer;
}