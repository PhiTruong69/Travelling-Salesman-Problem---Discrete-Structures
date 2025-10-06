<h1 align="center">🚏 Travelling Salesman Problem (TSP) — Held–Karp (Dynamic Programming)</h1>

<p align="center">
  <em>Giải bài toán Người Du Lịch bằng phương pháp Quy hoạch Động (Held–Karp)</em><br/>
  <small>Author: Hồng Phi Trường </small>
</p>

<hr/>

<h2>📘 Giới thiệu</h2>
<p>
Bài toán <strong>Travelling Salesman Problem (TSP)</strong> yêu cầu tìm đường đi ngắn nhất
đi qua tất cả các thành phố đúng một lần rồi quay về điểm xuất phát. Đây là một bài toán
tổ hợp khó (NP-hard). Trong dự án này ta triển khai thuật toán <strong>Held–Karp</strong>
(Quy hoạch động) để tính chính xác nghiệm cho số lượng thành phố vừa phải.
</p>

<hr/>

<h2>🧠 Ý tưởng thuật toán (Held–Karp)</h2>
<ul>
  <li>Sử dụng trạng thái <code>mask</code> (bitmask) biểu diễn tập các thành phố đã thăm.</li>
  <li>Bảng <code>dp[mask][u]</code> lưu chi phí nhỏ nhất để bắt đầu từ thành phố xuất phát,
      đã thăm các thành phố trong <code>mask</code> và hiện ở tại thành phố <code>u</code>.</li>
  <li>Công thức chuyển trạng thái: với mỗi <code>v</code> chưa thăm, cập nhật
      <code>dp[mask | (1&lt;&lt;v)][v] = min(dp[mask][u] + cost[u][v])</code>.</li>
  <li>Khi <code>mask == (1&lt;&lt;n)-1</code> (tất cả đã thăm) cộng chi phí quay về điểm xuất phát.</li>
  <li>Dùng mảng <code>parent</code> để truy vết đường đi tối ưu.</li>
</ul>

<hr/>

<h2>⚙️ Các bước thực hiện</h2>
<ol>
  <li>Đọc ma trận kề (ma trận khoảng cách) làm input.</li>
  <li>Khởi tạo <code>dp</code> với giá trị lớn (INF), đặt <code>dp[1&lt;&lt;start][start] = 0</code>.</li>
  <li>Duyệt tất cả các trạng thái <code>mask</code> (0 .. 2ⁿ-1) và cập nhật cho mọi cặp <code>u → v</code>.</li>
  <li>Sau khi hoàn thành, tìm chi phí nhỏ nhất kết thúc tại trạng thái đầy đủ và quay về start.</li>
  <li>Truy vết đường đi bằng mảng <code>parent</code> và xuất kết quả.</li>
</ol>

<hr/>

<h2>📈 Độ phức tạp</h2>
<ul>
  <li>Thời gian: <strong>O(2ⁿ × n²)</strong> (thực tế triển khai tối ưu hóa còn O(2ⁿ × n)).</li>
  <li>Bộ nhớ: <strong>O(2ⁿ × n)</strong> để lưu bảng <code>dp</code> và <code>parent</code>.</li>
</ul>

<hr/>

<h2>🔍 Đánh giá & Ghi chú</h2>
<ul>
  <li>Held–Karp phù hợp để giải chính xác TSP cho <em>n</em> nhỏ (thường n ≤ 20–22 tuỳ bộ nhớ/CPU).</li>
  <li>Với <em>n</em> lớn hơn, cần chuyển sang heuristic/approximation (branch-and-bound, genetic, ant-colony...).</li>
  <li>Trong mã nên xử lý trường hợp không liên thông (khoảng cách = 0 hoặc không tồn tại) bằng cách thay giá trị lớn (INF).</li>
</ul>

<hr/>

<h2>💻 Code</h2>
<p>File chính: <code>main.cpp</code> (có chứa triển khai DP, truy vết đường đi và in kết quả).</p>

<hr/>

<p align="center">
  <sub>Made with Phi Truong — If you want, I can add example inputs, visualization of the path, or complexity charts.</sub>
</p>

