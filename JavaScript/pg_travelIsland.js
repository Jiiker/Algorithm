Array.matrix = function (m, n, initial) {
  let a;
  let mat = [];
  for (let i = 0; i < m; i++) {
    a = [];
    for (let j = 0; j < n; j++) {
      a[j] = initial;
    }
    mat[i] = a;
  }
  return mat;
};

function solution(maps) {
  var answer = [];
  let S = [];
  let sum = 0;
  let vis = Array.matrix(maps.length, maps[0].length, 0);

  for (let i = 0; i < maps.length; i++) {
    for (let j = 0; j < maps[0].length; j++) {
      if (maps[i][j] == "X" || vis[i][j] == 1) {
        continue;
      }

      S.push([i, j]);
      sum = parseInt(maps[i][j]);
      vis[i][j] = 1;
      while (S.length > 0) {
        let cur = S.pop();
        let dir_x = [1, 0, -1, 0];
        let dir_y = [0, 1, 0, -1];

        for (let dir = 0; dir < 4; dir++) {
          let nx = cur[0] + dir_x[dir];
          let ny = cur[1] + dir_y[dir];

          if (nx >= maps.length || nx < 0 || ny >= maps[0].length || ny < 0) {
            continue;
          }
          if (maps[nx][ny] == "X" || vis[nx][ny] == 1) {
            continue;
          }

          S.push([nx, ny]);
          sum = sum + parseInt(maps[nx][ny]);
          vis[nx][ny] = 1;
        }
      }
      answer.push(sum);
    }
  }

  if (answer.length == 0) answer.push(-1);

  answer.sort((a, b) => a - b);

  return answer;
}
