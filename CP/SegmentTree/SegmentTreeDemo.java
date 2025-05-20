import java.util.*;

public class SegmentTreeDemo{

    public class SegmentTree{
        public int st[];
        public int lz[];
        public int n;

        public SegmentTree(int n) {
            this.n=n;
            this.st = new int[4*n+1];
            this.lz = new int[4*n+1];
            Arrays.fill(st, 0);
            Arrays.fill(lz, 0);
        }
        
        public void build(int st[], int arr[], int node, int s, int e){
            if(s==e){
                st[node]=arr[s];
                return;
            }
            int mid = (s+e)>>1;
            build(st,arr,2*node+1,s,mid);
            build(st,arr,2*node+2,mid+1,e);
            st[node]=st[2*node+1]+st[2*node+2];
        }

        public void build(int arr[]){
            build(st,arr,0,0,n-1);
        }

        int get(int st[], int lz[], int node, int curr_s, int curr_e, int s, int e){
            if(s>curr_e || e<curr_s)return 0;

            if(lz[node]!=0){
                st[node] += lz[node]*(curr_e-curr_s+1);
                if(curr_s!=curr_e){
                    lz[2*node+1] += lz[node];
                    lz[2*node+2] += lz[node];
                }
                lz[node]=0;
            }

            if(s<=curr_s && curr_e<=e)return st[node];
            
            int mid=(curr_s+curr_e)>>1;
            int left = get(st,lz,2*node+1,curr_s,mid,s,e);
            int right = get(st,lz,2*node+2,mid+1,curr_e,s,e);
            return left+right;
        }

        public int get(int s,int e){
            return get(st,lz,0,0,n-1,s,e);
        }

        public void update(int st[],int node, int s, int e, int idx, int val){
            if(s==e){
                st[node]=val;
                return;
            }

            int mid = (s+e)>>1;
            
            if(idx<=mid){
                update(st,2*node+1,s,mid,idx,val);
            }else{
                update(st,2*node+2,mid+1,e,idx,val);
            }
            st[node]=st[2*node+1]+st[2*node+2];
        }

        public void update(int index, int value){
            update(st,0,0,n-1,index,value);
        }

        public void rangeUpdate(int st[], int lz[], int node, int curr_s, int curr_e, int s, int e, int val){
            if(e<curr_s || curr_e<s)return;

            if(lz[node]!=0){
                st[node] += lz[node]*(curr_e - curr_s + 1);
                if(curr_s!=curr_e){
                    lz[2*node+1] += lz[node];
                    lz[2*node+2] += lz[node];
                }
                lz[node]=0;
            }

            if(s<=curr_s && curr_e<=e){
                st[node] += val*(curr_e - curr_s + 1);
                if(curr_s!=curr_e){
                    lz[2*node+1] += val;
                    lz[2*node+2] += val;
                }
                return;
            }

            int mid = (curr_s + curr_e)>>1;
            rangeUpdate(st, lz, 2*node+1, curr_s, mid, s, e, val);
            rangeUpdate(st, lz, 2*node+2, mid+1, curr_e, s, e, val);

            st[node] = st[2*node+1] + st[2*node+2];
        }

        public void rangeUpdate(int value, int s, int e){
            rangeUpdate(st,lz,0,0,n-1,s,e,value);
        }

    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int arr[] = new int[n];
        
        for(int i=0;i<n;i++)arr[i]=scanner.nextInt();

        SegmentTreeDemo classobj = new SegmentTreeDemo();
        SegmentTree ST = classobj.new SegmentTree(n);
        ST.build(arr);

        ST.update(2, 3);
        // int s,e;
        // s = scanner.nextInt();
        // e = scanner.nextInt();
        System.out.println(ST.get(1,4));

    }
}